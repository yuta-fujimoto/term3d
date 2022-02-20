# term3d
[![Norminette](https://github.com/yuta-fujimoto/term3d/actions/workflows/norm.yml/badge.svg)](https://github.com/yuta-fujimoto/term3d/actions/workflows/norm.yml) [![Test](https://github.com/yuta-fujimoto/term3d/actions/workflows/test.yml/badge.svg)](https://github.com/yuta-fujimoto/term3d/actions/workflows/test.yml)
```
make
./term3d torus.3d
````

* rotation.c

x, y 軸周りの回転
* keyaction.c

キーボード、いまのところh,j,k,lで回転、qで終了
* main.c 

投影処理、main

という感じで

- 入力処理きれいに(点の集合を可変長で、bufferです)
- 投影処理が違う([https://knzw.tech/raytracing/?page_id=1243](https://knzw.tech/raytracing/?page_id=1243))
- kbhitの理解
- 画面フラッシュする処理違う
- エラー処理

が未完成です
