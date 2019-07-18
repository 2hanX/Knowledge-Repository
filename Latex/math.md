### 模板

```latex
% pdfLaTeX
\documentclass{article}
\usepackage{amsmath}
\begin{document}

% you code here

\end{document}
```

### 注释

1. 方法1

   - 单行注释用`%`

2. 方法2

   - 多行注释用 `\iffalse `和 `\fi` 包含

3. 方法3

   - 多行注释使用包

   - ```latex
     \usepackage{verbatim}
     \begin{comment}
     comment here
     \end{comment}
     ```

     

### 在文本中嵌入公式

`this formula $f(x)=x^2$ is an example.`
$$
f(x)=x^2
$$

### 输出对齐

```latex
\begin{align*}
  1 + 2 &= 3\\
  1 &= 3 - 2
\end{align*}
```

$$
\begin{align*}
  1 + 2 &= 3\\
  1 &= 3 - 2
\end{align*}
$$

### 分数

```latex
\begin{align*}
  f(x) &= x^2\\
  g(x) &= \frac{1}{x}\\
  F(x) &= \int^a_b \frac{1}{3}x^3 \\
  t(x) &= \frac{1}{\sqrt{x}}
\end{align*}
```

$$
\begin{align*}
  f(x) &= x^2\\
  g(x) &= \frac{1}{x}\\
  F(x) &= \int^a_b \frac{1}{3}x^3\\
  t(x) &= \frac{1}{\sqrt{x}}
\end{align*}
$$

### 矩阵

```latex
\begin{matrix}
1 & 0\\
0 & 1
\end{matrix}
```

$$
\begin{matrix}
1 & 0\\
0 & 1
\end{matrix}
$$

### 括号

```latex
[
\begin{matrix}
1 & 0\\
0 & 1
\end{matrix}
]
\\ %分隔
\left[
\begin{matrix}
1 & 0\\
0 & 1
\end{matrix}
\right]
\\ %分隔
\left(\frac{1}{\sqrt{x}}\right)
```

$$
[
\begin{matrix}
1 & 0\\
0 & 1
\end{matrix}
]
\\ %分隔
\left[
\begin{matrix}
1 & 0\\
0 & 1
\end{matrix}
\right]
\\ %分隔
\left(\frac{1}{\sqrt{x}}\right)
$$



### 帮助文档或资源

- [wiki](https://en.wikibooks.org/wiki/LaTeX/Mathematics)
- [tutorial](https://www.latex-tutorial.com/tutorials/)
- [在线公式编辑器](https://zh.numberempire.com/latexequationeditor.php)