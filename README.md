# steganographic-fs

Filesystem criptografado com esteganografia. 
Para compilar basta rodar `make` na pasta raiz. O programa pode ser executado com `./steg-fs -d -s -f <path da pasta a ser montada>`

Para comparar as diferenças entre os dois bitmaps, é possível usar o comando `cmp -l <imagem1> <imagem2> | gawk '{printf "%08X %02X %02X\n", $1, strtonum(0$2), strtonum(0$3)}'`
