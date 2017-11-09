cc_library(
  name = 'knn',
  srcs = ['knn.cc'],
  hdrs = ['knn.h'],
  copts = ["-Iexternal/gtest/include"],
  deps = [
    '//external:gflags',
    '@gtest//:main',
    "@com_github_glog_glog//:glog",
    "@com_google_protobuf_cc//:protobuf",
  ],
)

cc_test(
  name = 'knn_test',
  srcs = ['knn_test.cc'],
  copts = ["-Iexternal/gtest/include"],
  deps = [
    ':knn',
    '@gtest//:main',
  ],
  )
