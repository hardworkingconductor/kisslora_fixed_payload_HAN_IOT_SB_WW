# kisslora_fixed_payload_HAN_IOT_SB_WW
This project is a fork based on the [HAN IoT KISS LoRa](https://gitlab.com/wlgrw/han-iot-kiss-lora) 
This is the main page to the KissLoRA payload encoder improvement.


# Getting Started
There are some Prerequites necessary to boot and understand the code.


## Prerequites
- Arduino software
- C++
- Javascript
- Doxygen
- Kiss LoRA device

`git clone https://github.com/hardworkingconductor/kisslora_fixed_payload_HAN_IOT_SB_WW.git`

Generate the Doxygen wizard with the kisslora_fixed_payload_HAN_IOT_SB_WW folder as input and select your preferred output folder.
Finally, follow the instructions in the comment code of the LoRa_TX_RX_Cayenne_HAN.ino



# Problem case
Currently the HAn IoT Kiss LoRA payload encoder is using up too much RAM which cripples the possibility of future component additions for the board.
This project was thus made with the goal of optimizing the payload encoder.


# Disclaimer
The content of this repository is provided in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.


# License
This repository is free: You may redistribute it and/or modify it under the terms of a Creative  Commons Attribution-NonCommercial 4.0 International License  (http://creativecommons.org/licenses/by-nc/4.0/)
  



