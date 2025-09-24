Modify contents of source file:
```
for i in {0..9}; do cp play.cpp play${i}.cpp; sed -i "s/A/${i}/g" play${i}.cpp; done
```
Compilation:
```
for i in {0..9}; do clang++ -std=c++20 play${i}.cpp -o a${i}.out; done
```
Create Dockerfile from template and populate with correct binary:
```
for num in {0..9}; do sed "s/a\.out/a${num}.out/g" template.txt > Dockerfile; sudo docker build -t foo${num} .; done
```
Run:
```
for i in {0..9}; do sudo docker run -d foo${i}; done
```
Kill:
```
for i in {0..9}; do sudo docker kill foo${i}; done
```
Delete containers:
```
sudo docker rm $(sudo docker ps -aq)
```
Delete images:
```
sudo docker rmi $(sudo docker images -aq)
```
