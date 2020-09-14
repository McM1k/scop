if [ ! -f src/glad.c -a inc/glad.h -a inc/khrplatform.h ]; then
git clone https://github.com/Dav1dde/glad.git
cd glad
python -m glad --profile core --out-path . --api "gl=4.1" --generator c --spec gl --local-files
cd ..
cp glad/glad.c src
cp glad/*.h inc
rm -rf glad
fi
