function decodeUplink(input) {
    var data = {};

    if(input.bytes.length === 2){
    data.presence = input.bytes[0];
    data.digIN = input.bytes[1];
    } else{
    data.temperature =
    (((input.bytes[0] & 0x80 ? input.bytes[0] - 0x100 : input.bytes[0]) << 8) +
      input.bytes[1]) /
    10;
    data.humitidy = ((input.bytes[2] & 0x80 ? input.bytes[2] - 0x100 : input.bytes[2]) << 8); //controleer deze functie
    data.light = (input.bytes[3] << 8) + input.bytes[4];
    data.rotpos = input.bytes[5];
    data.acX =  (((input.bytes[6] & 0x80 ? input.bytes[6] - 0x100 : input.bytes[6]) << 8) +
      input.bytes[7]) /
    1000;
    data.acY =  (((input.bytes[8] & 0x80 ? input.bytes[8] - 0x100 : input.bytes[8]) << 8) +
      input.bytes[9]) /
    1000;
    data.acZ =  (((input.bytes[10] & 0x80 ? input.bytes[10] - 0x100 : input.bytes[10]) << 8) +
      input.bytes[11]) /
    1000;
    //dit werkt niet, fix het
    data.analogIN =
    (((input.bytes[12] & 0x80 ? input.bytes[12] - 0x100 : input.bytes[12]) << 8) +
      input.bytes[13]) /
    100;
    data.presence = input.bytes[14];
    data.analogOUT =
    (((input.bytes[15] & 0x80 ? input.bytes[15] - 0x100 : input.bytes[15]) << 8) +
      input.bytes[16]) /
    100;
    
    }
    
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
      },
    };
  }
