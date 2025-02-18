# HLW8032_Library
Library HLW8032 file with example application using STM32F407VGT6

The HLW8032 sends 24 bytes data via serial communication in the following format:

| Data Type          | Length<br>(byte)|
|:-------------------|:------------:|
| State REG          |   1          |
| Check REG          |   1          |
| Volt param REG     |   3          |
| Volt REG           |   3          |
| Current param REG  |   3          |
| Current REG        |   3          |
| Power Param REG    |   3          |
| Power REG          |   3          |
| Data update REG    |   1          |
| PF REG             |   2          |
| Checksum REG       |   1          |

Measurements calculation:
**VOLTAGE**
  \(\frac{{\text{{Volt param REG}} \times \text{{Volt coefficient*}}}}{{\text{{Volt REG}}}}\)

**CURRENT**
\(\frac{{\text{{Current param REG}} \times \text{{Current coefficient*}}}}{{\text{{Current REG}}}}\)

**ACTIVE POWER**
\(\frac{{\text{{Power param REG}} \times \text{{Power coefficient*}}}}{{\text{{Power REG}}}}\)

**APPARENT POWER**
\( \text{Voltage} \times \text{Current} \)

**POWER FACTOR**
\( \frac{\text{Active Power}}{\text{Apparent Power}} \)

*Typical Coefficient:
Volt Coefficient        = 1.88
Current Coefficient     = 1
- You can adjust the coefficient value

for more information you can follow the link:
https://www.lcsc.com/datasheet/lcsc_datasheet_2307271600_Hiliwei-Tech-HLW8032_C128023.pdf