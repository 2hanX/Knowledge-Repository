`vim /etc/ssh/sshd_config`

```
PasswordAuthentication yes
PermitRootLogin yes
```

`/etc/init.d/ssh start`

`service ssh start`

`update-rc.d ssh enable`

`update-rc.d ssh disable`

