

```
struct sockaddr_storage {
    ADDRESS_FAMILY ss_family;      // address family
    CHAR __ss_pad1[_SS_PAD1SIZE];  // 6 byte pad, this is to make
                                   //   implementation specific pad up to
                                   //   alignment field that follows explicit
                                   //   in the data structure
    __int64 __ss_align;            // Field to force desired structure
    CHAR __ss_pad2[_SS_PAD2SIZE];  // 112 byte pad to achieve desired size;
                                   //   _SS_MAXSIZE value minus size of
                                   //   ss_family, __ss_pad1, and
                                   //   __ss_align fields is 112
} 
```













