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
    data.temp = (input.bytes[0] << 8) + input.bytes[1];
   // pen.humitidy = input.byes[2];
    data.light = (input.bytes[3] << 8) + input.bytes[4];
    
    data.temperature =
      (((input.bytes[4] & 0x80 ? input.bytes[4] - 0x100 : input.bytes[4]) << 8) +
        input.bytes[5]) /
      100;
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