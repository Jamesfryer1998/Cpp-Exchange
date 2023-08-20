# C++ Exchange

## Instructions to run project
 - When adding/removing a file use:
 ```
   `cmake -B build`
 ```
 - When editing code within the repo:<br>
    ```
    `cmake --build build`
    ```
 - To run the project:<br>
   ```
   `./build/main/main`
   ```

### Create a new git branch
```
git checkout -b branch_name
git push origin branch_name
git commit -a "commit your changes"
git push --set-upstream origin OrderBook
```

### Merge to main branch
```
git checkout main
git merge branch_name
git branch -d branch_name (Deletes local branch)
git push origin main
git push origin main --delete branch_name (Deletes remote branch)
```
