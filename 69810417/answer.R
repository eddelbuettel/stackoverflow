

D <- structure(list(PCode = c("57651", "57652", "57664", "57668",  "57671", "57671", "57688", "57689", "57692", "57695"), VisitDate = structure(c(1586304000,  1586304000, 1586908800, 1586390400, 1586304000, 1587168000, 1586908800,  1607040000, 1586476800, 1586649600), tzone = "UTC", class = c("POSIXct",  "POSIXt")), "PCode"= c("PCode", "PCode", "PCode", "PCode",  "PCode", "PCode", "PCode", "PCode", "PCode", "PCode")), class = c("grouped_df",  "tbl_df", "tbl", "data.frame"), row.names = c(NA, -10L), groups = structure(list("PCode" = "PCode", .rows = structure(list(1:10), ptype = integer(0), class = c("vctrs_list_of",  "vctrs_vctr", "list"))), class = c("tbl_df", "tbl", "data.frame" ), row.names = c(NA, -1L), .drop = TRUE))

now <- Sys.time()
now
class(now)

D$dt <- as.numeric(difftime(now, D$VisitDate, "days"))
D
