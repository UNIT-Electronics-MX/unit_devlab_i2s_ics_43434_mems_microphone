#include <driver/i2s.h>

#define I2S_WS 37
#define I2S_SD 35
#define I2S_SCK 36

#define CHANNEL_PIN 34
// Pines recomendados si los 35,36,37 no funcionan
// #define I2S_WS   7
// #define I2S_SD   5
// #define I2S_SCK  6
#define MIC_CHANNEL_LEFT  0
#define MIC_CHANNEL_RIGHT 1

#define MIC_CHANNEL MIC_CHANNEL_RIGHT
#define I2S_PORT I2S_NUM_0
#define bufferLen 64

int32_t sBuffer[bufferLen];

void i2s_install() {
  const i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
    .sample_rate = 16000,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,
    .channel_format =
    #if (MIC_CHANNEL == MIC_CHANNEL_LEFT)
        I2S_CHANNEL_FMT_ONLY_LEFT,
    #else
        I2S_CHANNEL_FMT_ONLY_RIGHT,
    #endif
    .communication_format = I2S_COMM_FORMAT_I2S,
    .intr_alloc_flags = 0,
    .dma_buf_count = 8,
    .dma_buf_len = bufferLen,
    .use_apll = false,
    .tx_desc_auto_clear = false,
    .fixed_mclk = 0
  };

  i2s_driver_install(I2S_PORT, &i2s_config, 0, NULL);
}

void i2s_setpin() {
  const i2s_pin_config_t pin_config = {
    .bck_io_num = I2S_SCK,
    .ws_io_num = I2S_WS,
    .data_out_num = I2S_PIN_NO_CHANGE,
    .data_in_num = I2S_SD
  };

  i2s_set_pin(I2S_PORT, &pin_config);
}

void setup() {
  Serial.begin(115200);
  delay(1000);
pinMode(CHANNEL_PIN, OUTPUT);

#if (MIC_CHANNEL == MIC_CHANNEL_LEFT)
digitalWrite(CHANNEL_PIN, LOW);
#else
digitalWrite(CHANNEL_PIN, HIGH);
#endif
  i2s_install();
  i2s_setpin();
  i2s_start(I2S_PORT);

  Serial.println("I2S iniciado");
}

void loop() {
  int rangelimit = 3000;

  Serial.print(-rangelimit);
  Serial.print(" ");
  Serial.print(rangelimit);
  Serial.print(" ");

  size_t bytesIn = 0;

  esp_err_t result = i2s_read(
    I2S_PORT,
    sBuffer,
    sizeof(sBuffer),
    &bytesIn,
    portMAX_DELAY);

  if (result == ESP_OK && bytesIn > 0) {
    int muestras = bytesIn / sizeof(int32_t);

    float promedio = 0;

    for (int i = 0; i < muestras; i++) {
      promedio += (sBuffer[i] >> 14);
    }

    promedio /= muestras;

    Serial.println(promedio);
  }
}