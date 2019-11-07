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

### 找出内存消耗最大的进程

1. `ps aux --sort -rss | head` [^4]
2. `ps -eo pid,ppid,%mem,%cpu,cmd --sort=-%mem | head` [^5]
3. ` top -c -b -o +%MEM | head -n 20 | tail -15`

### 目录|文件大小排序

1. `du -hs [文件路径] 或者 du -hs --max-depth=0 /home`[^6]
2. `du -hs /home/* | sort -rh | head -10`



---

[^1]: 加密`123456`为例，md5 密文值是 `e10adc3949ba59abbe56e057f20f883e`
[^2]: `-n`：表示不输入回车符
[^3]: 文件末尾不能有回车符，`echo -n 123456 > file.txt`
[^4]: 
[^5]: 仅展示有关内存消耗过程的特定信息
[^6]: 目录总大小