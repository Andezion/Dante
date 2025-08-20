const std = @import("std");

pub fn main() !void {
    var stdin = std.io.getstdin().reader();
    var stdout = std.io.getstdout().writer();

    try stdout.print("Enter 5 numbers: ", .{});

    var buffer: [100]u8 = undefined;
    const line = try stdin.readUntilDelimiterOrEof(&buffer, '\n');

    var iter = std.mem.tokenizeAny(u8, line.?, " \t");
    var nums: [5]f32 = undefined;

    var i: usize = 0;
    while (iter.next()) |tok| : (i += 1) {
        if (i >= nums.len) break;
        nums[i] = try std.fmt.parseFloat(f32, tok);
    }

    const sum: f32 = nums[0] + nums[1] + nums[2] + nums[3] + nums[4];
    const middle: f32 = sum / 5.0;

    var max: f32 = nums[0];
    var min: f32 = nums[0];

    if (nums[1] > max) max = nums[1];
    if (nums[2] > max) max = nums[2];
    if (nums[3] > max) max = nums[3];
    if (nums[4] > max) max = nums[4];

    if (nums[1] < min) min = nums[1];
    if (nums[2] < min) min = nums[2];
    if (nums[3] < min) min = nums[3];
    if (nums[4] < min) min = nums[4];

    try stdout.print("Result: min = {}, max = {}, middle = {}\n", .{ min, max, middle });
}
