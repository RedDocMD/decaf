load("@rules_antlr//antlr:antlr4.bzl", "antlr")
load("@rules_cc//cc:defs.bzl", "cc_library")

antlr(
    name = "grammar",
    srcs = glob(["*.g4"]),
    language = "Cpp",
    layout = "grammar",
    package = "grammar",
    visitor = True,
)

cc_library(
    name = "grammar_lib",
    srcs = [":grammar"],
    visibility = [
        "//ast:__pkg__",
        "//main:__pkg__",
    ],
    deps = [
        ":grammar",
        "@antlr4_runtimes//:cpp",
    ],
)
