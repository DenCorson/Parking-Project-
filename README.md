Too keep fork updated, do the following from within the remote repository: 

1. Add the original repository as a remote:
   - git remote add upstream https://github.com/DenCorson/Parking-Project-.git
2. Fetch changes from the original repository:
   - git fetch upstream
3. Merge changes into your branch:
   - git merge upstream/main


Steps to push:
1. `git add .`
2. `git commit -m '<commit message>'`
3. `git push origin add-strategy-pattern`

Steps to run from
1. `g++ <file_name>.cpp -o <output_file_name>`
2. `./<output_file_name>`