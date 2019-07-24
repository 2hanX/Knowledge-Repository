### 修改本地主机网络设置

`netsh`

`netsh interface ipv4 set address name="WLAN" source=static addr=192.168.1.100 mask=255.255.255.0 gateway=192.168.1.1 gwmetric=0`

### 端口转发

```powershell
netsh interface portproxy add v4tov4 listenaddress=192.168.1.100 listenport=8888 connectaddress=192.168.1.110 connectport=8889 # 添加规则
netsh interface portproxy delete v4tov4 listenaddress=192.168.1.100 listenport=8888 # 取消端口转发
netsh interface portproxy show all #查看所有转发规则
```

