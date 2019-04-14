echo "# $1" >> README.md
git init
git add .
git commit -m "first commit"
git remote add origin https://github.com/Alteracia/$1.git
git push -u origin master