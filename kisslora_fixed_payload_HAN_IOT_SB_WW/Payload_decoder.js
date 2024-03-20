/*
To use this custom payload decoder go to payload formatters in your
things network console.
Then click on the uplink and select custom javascript.
paste this code there and save it.
*/

function decodeUplink(input) {
    var data = {};
    
    //checks if the data is the short message or the long message
    if(input.bytes.length === 2){
    //short message
    data.presence = input.bytes[0];
    data.digIN = input.bytes[1];
      
    } else{
    //long message
    data.temperature =
    (((input.bytes[0] & 0x80 ? input.bytes[0] - 0x100 : input.bytes[0]) << 8) +
      input.bytes[1]) /
    10;
    //calculates the unsigned value back into a signed value
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

    return {
      data: data,
    };
  }

  function normalizeUplink(input) {
    return {
      data: {
      },
    };
  }
