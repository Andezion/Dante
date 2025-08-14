const std = @import("std");

pub fn main() !void {
        try std.fs.File.stdout().writeAll("\"one\"\n\"two\"\n\"three\"\n\"four\"\n\"five\"\n");
}

