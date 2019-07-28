## Exiftool[^1]

`exiftool -h`

`exiftool -h > exiftool_h.txt`

### 查看 EXIF 信息

`exiftool photo.jpg` [^2]

`exiftool -s -ImageSize -ExposureTime b.jpg` [^3]

`exiftool -l -canon c.jpg d.jpg`

### 更改信息

`exiftool -gps:all= photo.jpg` [^4]

`exiftool -all= photo.jpg` [^5]

`exiftool -all= --exif:all photo.jpg` [^6]

`exiftool -filename=new.jpg dir/old.jpg`

### 写入信息

`exiftool -artist=me photo.jpg`

`exiftool -comment="new comments" photo.jpg`

`exiftool -keywords=EXIF -keywords=editor dst.jpg`

`...`



---

[^1]: 图片 EXIF信息查看器
[^2]: 默认显示所有信息；注意查看` File Type` 字段与文件名后缀是否一致
[^3]: 查看图片尺寸
[^4]: 删除图片中 GPS 信息
[^5]: 删除所有信息
[^6]: 删除EXIF以外的所有信息