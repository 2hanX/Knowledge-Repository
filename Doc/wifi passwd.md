## 获取WiFi密码

### 配置文件存储位置

`HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\WZCSVC\Parameters\Interfaces\{interfaceID}` [^2]

`C:\ProgramData\Microsoft\Wlansvc\Profiles\Interfaces\{interfaceID}\{profileID}.xml` [^1]

- 签名字段 `01000000D08C9DDF0115D1118C7A00C0`

### 人工解密方法

1. 通过系统上下文执行解密操作
   - 通过系统进程中的[远程线程](https://securityxploded.com/ntcreatethreadex.php)注入代码-`LSASS.exe` 
   - 将Windows服务创建为系统帐户，然后从该服务执行下述解密代码`

```c
//
//无线配置管理器使用 CryptProtectData 加密无线密钥
//适用于Vista / Windows 7 / Windows 8 / Windows 10的无线密钥/密码解密算法
//
void DecryptWiFiPassword（BYTE * buffer，DWORD dwSizeBuffer）
{
	DATA_BLOB DataIn;
	DATA_BLOB DataOut;
	
 	DataIn.pbData = buffer;
	DataIn.cbData = dwSizeBuffer;
			
	if（CryptUnprotectData（＆DataIn，0，NULL，NULL，NULL，0，＆DataOut））
	{
		printf（“\ n无线密钥：％s”，（char *）DataOut.pbData）;

	}
 }
```



### cmd

```powershell
netsh wlan show profile #列出所有无线配置文件
netsh wlan show profile name="<name from the list of profiles>" key=clear #明文显示PSK
```



---

[^1]: 适用于 Vista，Windows 7，Windows 8和Windows 10，密码存储在 `<sharedKey>` 节点下 `<keyMaterial>`字段
[^2]: 适用于 Windows XP/2003 ，使用 [Windows Cryptography](https://docs.microsoft.com/zh-cn/windows/win32/seccrypto/cryptography-functions#data_encryption_and_decryption_functions) 加密