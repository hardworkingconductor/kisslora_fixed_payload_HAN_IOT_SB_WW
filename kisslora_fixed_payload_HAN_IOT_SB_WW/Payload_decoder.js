function decodeUplink(input) {
    var data = {};
    var pen= {};
    var events = {
      1: "setup",
      2: "interval",
      3: "motion",
      4: "button",
    };
    data.event = events[input.fPort];
    data.temperature =
    (((input.bytes[0] & 0x80 ? input.bytes[0] - 0x100 : input.bytes[0]) << 8) +
      input.bytes[1]) /
    10;
    data.humitidy = input.bytes[2];
    data.light = (input.bytes[3] << 8) + input.bytes[4];


    var warnings = [];
    if (data.temperature < -10) {
      warnings.push("it's cold");
    }
    return {
      data: data,
      warnings: warnings,
    };
  }
  
  function normalizeUplink(input) {
    return {
      data: {
        air: {
          temperature: input.data.temperature,
        },
      },
    };
  }
