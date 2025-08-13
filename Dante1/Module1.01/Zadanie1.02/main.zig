const std = @import("std");

pub fn main() !void {
	try std.fs.File.stdout().writeAll("one\ntwo\nthree\nfour\nfive\n");
}
