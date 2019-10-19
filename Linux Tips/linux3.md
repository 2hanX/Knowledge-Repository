### md5 加密 [^1]

1. ```shell
   linux:# openssl
   OpenSSL> md5
   123456(stdin)= e10adc3949ba59abbe56e057f20f883e
   # 输入123456后不要输入回车，直接连续按3次 `ctrl+d`
   ```

2. `echo -n 123456 | openssl md5` [^2]

3. `echo -n 123456 | md5sum`

4. `md5sum file.txt` [^3]



---

[^1]: 加密`123456`为例，md5 密文值是 `e10adc3949ba59abbe56e057f20f883e`
[^2]: `-n`：表示不输入回车符
[^3]: 文件末尾不能有回车符，`echo -n 123456 > file.txt`