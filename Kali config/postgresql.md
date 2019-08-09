`service postgresql start`

`msfdb init`

### 共享数据库

`vim /etc/postgresql/11/main/postgresql.conf`

`vim /etc/postgresql/11/main/pg_hba.conf`

```
host    replication     postgres        ::1/128                 md5
```

### 远程连接

`psql -U postgres -d postgres -h xxx.xxx.xxx.xxx -W`

### Ref.

- [cnblogs](https://www.cnblogs.com/xjnotxj/p/11198255.html)

