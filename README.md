# leetcode-top-interview-150

# pushing to git:

this process assumes you have already created a repository
on GitHub or have an existing repository owned by someone 
else you'd like to contribute to, or, cloned the repository
locally on your computer

1. On your computer, move the file you'd like to upload to
GitHub into the local directory that was created when you
cloned the repository.

2. open terminal

3. change the current working directory to your local repository

4. stage the file for commit to your local repository

git add .

Adds the file to your local file and stages it for commit
To unstage a file, use
git reset HEAD YOUR-FILE

5. Commit the file that you've staged in your local repository

git commit -m "your comment goes here, it can be anything"
commits the tracked changes and prepares them to be pushed

to a remote repository. To remove this commit and modify the
file, use 
git reset --soft HEAD~1
and commit and add the file again

ie. git commit -m "first commit"

6. Push the changes in your local repository to GitHub.com

git push origin YOUR_BRANCH

pushes the changes in your local repository up to the
remote repository you specified as the origin

ie. git push origin main
