git clone https://github.com/Dav1dde/glad.git
cd glad
python -m glad --profile core --out-path . --api "gl=4.1" --generator c --spec gl --local-files
cd ..
cp glad/glad.c srcs
cp glad/*.h includes
rm -rf glad

