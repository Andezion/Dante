const print = @import("std").debug.print;

pub fn main() !void {
	const array =  [10]i32 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (array) |i| {
		print("{d} ", .{i});
	}
}
