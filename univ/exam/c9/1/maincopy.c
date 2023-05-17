#include "libftcopy.h"

int main(void)
{
    ft_putdouble(1.1111, 5);
    puts("double");
    printf("%zu;", ft_strlen("123456"));
    puts("strlen");
    return (0);
}

/*
プロセス
１静的ライブラリの作成
｜ー静的ライブラリとは複数の関数を集めた、関数の集合体と思えば良い。
｜　集めるのは、関数が記述された複数の.oファイル（.cからそれぞれ変換する）。
｜ー.oファイルをまとめて、.aファイルを作成する（このときもコードが必要）
｜　ここまでの2stepのコードはlibft_creator.shに記述されてる。
２静的ライブラリとメインプログラムのリンク
｜ーメインプログラムを実行ファイルにするときに、main.cと.aとのリンクが必要
｜ーこのときにヘッダーファイルがどのように機能するのか？
｜　まずmain.cには参照するヘッダーファイルを記述しておく
｜　参照先のヘッダーファイルには、mainで利用する関数のプロトタイプ宣言
｜ーーこのプロトタイプ宣言は、１で集めた関数の内、利用する関数を宣言する
|-ではリンク方法は？コンパイル時にコードをちょこっと追記する。
｜ーーcc main.c -l lftのように「-l」オプションを利用して、-lの後にライブラリのファイル名を記載すことができる。このときlibft.aのlib->l に .aは省略しても良い。
｜ーー他にも「cc main.c libft.a」のようにコンパイルしてもいい。
*/