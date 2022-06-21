phe_num <- 1
cross_num <- 1
chr_num <- 1
pfn <- paste0("pred_ukb_pheno",
                   phe_num,
                   "_fold",
                   cross_num,
                   "_chr",
                   chr_num,
                   "_best.dblsmm.txt.profile")
profile_fn <- file.path("/net/mulan/home/fredboe/research/ukb-intervals/dat", "simulations-ding", "DBSLMM", pfn)
file.exists(profile_fn)
#> [1] FALSE
profile_fn
#> [1] "/net/mulan/home/fredboe/research/ukb-intervals/dat/simulations-ding/DBSLMM/pred_ukb_pheno1_fold1_chr1_best.dblsmm.txt.profile"
my_file <- "/net/mulan/home/fredboe/research/ukb-intervals/dat/simulations-ding/DBSLMM/pred_ukb_pheno1_fold1_chr1_best.dbslmm.txt.profile"
file.exists(my_file)
#> [1] TRUE
my_file == profile_fn
#> [1] FALSE
