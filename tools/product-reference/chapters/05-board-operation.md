## **5 Preliminary Operation Notes**

The firmware under `software/examples/i2s/` is experimental and remains under
test, so it is intentionally not reproduced as a validated example here.

For initial bench work:

1. Inspect the board and ensure the bottom acoustic port is unobstructed.
2. Verify the `VIN`/`VSYS` power path against a schematic or measured board.
3. Connect the host and module grounds.
4. Connect host I²S bit clock to `SCK`, word select to `WS`, and receive data
   to `SD`.
5. Set `CH` low for the left time slot or high for the right time slot.
6. Start with conservative audio settings and confirm framing using a logic
   analyzer before relying on captured sample values.

Host GPIO numbers are controller-specific and are not module pin numbers.
Clock limits, tested sample rates, sample alignment, and controller examples
will be added after validation.
