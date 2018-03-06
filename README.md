# How to update to the alternate code base

1. On your local clone, do `git rm *` to remove all existing files.
2. Download the files from commit [c56177fc62ee721709c56d3e07725f758359a736](http://ares-mat17.cs.uleth.ca/gitlab/cpsc3720/CodeReviewSpring2018/AlternateCodebase/tree/c56177fc62ee721709c56d3e07725f758359a736).
3. Extract the files into your local clone's directory. Make sure that you are not creating a new sub-directory, but keeping the previous directory structure (i.e. `src/test/include` should be at the top level).
4. Run `git add *` to add the new files to your clone.
5. Run `git commit` to commit the changes.
6. On GitLab, go to `Settings->Repository->Protected Branches`.
7. Unprotect the `master` branch.
7. Run `git push -f origin master` to force the remote repository to accept the commit.
 

