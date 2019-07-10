## nslookup[^1]

### DNS系统

- DNS查找顺序
  - 浏览器缓存 > 本地操作系统缓存 > DNS服务器(路由缓存 >互联网DNS缓存服务器)
  - 浏览器缓存： `chrome://net-internals/#dns:`
  - 本地操作系统缓存: （hosts文件设置）：`ipconfig /displaydns`

### DNS 记录类型

| 标记段 | 说明                                | 描述                                                         | 使用示例                                                     |
| ------ | ----------------- | ---------------------------------------------------------- | ------------------------------------------------------------ |
| A      | 地址记录(address)(Ipv4)             | 指的是用来指定主机名或域名对应的IP记录               | `nslookup`<br />`> set type=a`<br />或者`> set querytype=a`<br />`> baidu.com` <br />或 ==`nslookup -qt=a baidu.com`==|
| AAAA   | 地址记录（Ipv6）                    |                                                              |                                  |
| AFSDB  | Andrew文件系统数据库服务器记录      |                                                              |              |
| ATMA   | ATM地址记录                         |                                                              |                                                              |
| CNAME  | 别名记录[^3]                        | 允许将多个名字映射到同一台计算机                             | `nslookup`<br />`> set type=cname`<br/> `baidu.com`|
| HINFO  | 硬件配置记录，包括CPU、操作系统信息 |                                  |                        |
| ISDN   | 域名对应的ISDN号码                  |                                |                              |
| MB     | 存放指定邮箱的服务器                |                                   |                        |
| MG     | 邮件组记录                          |                      |                       |
| MINFO  | 邮件组和邮箱的信息记录              |                   |                                      |
| MR     | 改名的邮箱记录                      |                     |                                        |
| MX     | 邮件服务器记录(mail exchanger)[^2]  | 邮件交换记录，它指向一个邮件服务器，用于电子邮件系统，发邮件时根据收信人的地址后缀来定位邮件服务器 | `nslookup`<br />`> set type=mx`<br />`> baidu.com`           |
| NS     | 名字服务器记录(nameserver)          | 用来指定该域名由那个DNS服务器来进行解析           | `nslookup`<br /> `set type=ns`<br />`baidu.com`|
| PTR    | 反向记录                            | 反向查询（IP查域名） | `nslookup -qt=ptr 14.215.177.38` |
| RP     | 负责人记录                          |                                   |                                                              |
| RT     | 路由穿透记录                        |                                                              |                                                              |
| SRV    | TCP服务器信息记录                   |                                                              |                                     |
| TXT    | 域名对应的文本信息                  |                                                              |                                                              |
| X25    | 域名对应的X.25地址记录              |                                                              |           |

### 高级使用

```powershell
nslookup
> help #查看帮助信息
> set all #打印当前服务器和主机
> server NAME #将默认服务器设置为 NAME，使用当前默认服务器
> set debug
> set d2
```

### 问题

| 问题              | 原因                    | 解决方案                                                     |
| ----------------- | ----------------------- | ------------------------------------------------------------ |
| 默认服务器Unknown | DNS服务器未配置反向解析 | **更换DNS服务器地址**<br />cmd下进入网络连接面板 `ncpa.cpl`<br />选择当前上网网卡，进入属性面板修改IPv4里的DNS服务器地址 |
| DNS 请求时间超时  |                         | **更换DNS服务器地址**<br />可以改为`8.8.8.8`                 |



---

[^1]: `nslookup`（name server lookup，域名查询）用于查询DNS的记录，查看域名解析是否正常，在网络故障的时候用来诊断网络问题；进入`nslookup`后输入`help`查看帮助信息
[^2]: `MX perference = 10` 指 MX 记录的优先级
[^3]: `ttl`值表示DNS记录在DNS服务器上缓存时间