```
for i in {0..9}; do cp play.cpp play${i}.cpp; sed -i "s/A/${i}/g" play${i}.cpp; done
```

```
for i in {0..9}; do clang++ -std=c++20 play${i}.cpp -o a${i}.out; done
```

```
for num in {0..9}; do sed "s/a\.out/a${num}.out/g" template.txt > Dockerfile; sudo docker build -t foo${num} .; done
```

```
for i in {0..9}; do sudo docker run -d foo${i}; done
```

```
for i in {0..9}; do sudo docker run -d foo${i}; done
```

```
for i in {0..9}; do sudo docker kill foo${i}; done
```
