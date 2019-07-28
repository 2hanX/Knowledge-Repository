## Sniffer Mode

`snort -W`

`snort -v -i [interface]` [^1]

`snort -vd -i [interface]` [^2]

`snort -dev -i [interface]`[^3]

## Packet Logger Mode

`snort -dev -q -l C:\Snort\log -i [interface] -c C:\Snort\etc\snort.conf `

`snort -dev -l ./log -h 192.168.1.0/24`

`snort -l ./log -b`[^4]

`snort -r [snort_log]`

`snort -dvr [snort_log] icmp` [^5]

## NIDS Mode

`snort -dev -l ./log -h 192.168.1.0/24 -c snort.conf`

`snort -i [interface] -c snort.conf -A console -q`



---

[^1]: print out the TCP/IP packet headers to the screen
[^2]: print out the application data in transit
[^3]: showing the data link layer headers
[^4]: log the packets in binary mode
[^5]: filter，see ICMP packets from the log file