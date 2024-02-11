<h2>Process for changing submodules</h2>
<p>
If you've made changes within a submodule and you want to commit those changes, follow these steps:
</p>

<h4> Review and stage your changes. </h4>
<p> In this stage you need to review your stages (optional), stage them and finally push them to the submodule's repository </p>

```
# Switch to the submodule's dir
cd path/to/submodule

git status

git add .

# Optionally, review the changes again
git status

git commit -m "Your commit message here"
```

<h4> Stage and commit the changes in the main repository </h4>
<p>
The changes in the submodule need to be added to the parent repository as well.
</p>

```
git add .
git commit -m "Update submodule to latest commit"
```

<p>
This step is essential because it updates the reference in your main project to point to the specific commit in the submodule where you made changes.
</p>

<h4> Push Changes for both repositories </h4>
<p>
If you want to push your changes to a remote repository, don't forget to push both the submodule and the main project.
</p>

```
# Push submodule changes
cd path/to/submodule
git push

# Push main project changes
cd ..
git push
```