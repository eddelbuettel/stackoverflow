
AP <- available.packages()       ## all known package given options("repos")
res <- AP[ AP[,1] == "rlang", ]  ## find rlang

str(res)

names(res)

res["Repository"]
