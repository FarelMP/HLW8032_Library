# HLW8032_Library
Library HLW8032 file with example application using STM32F407VGT6

The HLW8032 sends 24 bytes data via serial communication in the following format:

| Data Type          | Length |
|                    | (byte) |
|:-------------------|:------:|
| State REG          |   1    |
| Check REG          |   1    |
| Volt param REG     |   3    |
| Volt REG           |   3    |
| Current param REG  |   3    |
| Current REG        |   3    |
| Power Param REG    |   3    |
| Power REG          |   3    |
| Data update REG    |   1    |
| PF REG             |   2    |
| Checksum REG       |   1    |

Measurements calculation:
- Voltage           = (Volt param REG x Volt coefficient*)/Volt REG
- Current           = (Current param REG x Current coefficient*)/Current REG
- Active power      = (Power param REG x Volt coefficient x Current coefficient)/Power REG
- Apparent power    = Voltage x Current
- Power Factor      = Active power/Apparent power

*Typical Coefficient:
Volt Coefficient        = 1.88
Current Coefficient     = 1
- You can adjust the coefficient value

for more information you can follow the link:
https://www.lcsc.com/datasheet/lcsc_datasheet_2307271600_Hiliwei-Tech-HLW8032_C128023.pdf