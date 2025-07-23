pub fn add_int(a: i32, b: i32) -> i32 {
    a + b
}
pub fn sub_int(a: i32, b: i32) -> i32 {
    a - b
}
pub fn mul_int(a: i32, b: i32) -> i32 {
    a * b
}
pub fn div_int(a: i32, b: i32) -> i32 {
    if b == 0 {
        return 0;
    }
    a / b
}

pub fn calculate(a: i32, b: i32, f: fn(i32, i32) -> i32) -> i32 {
    f(a, b)
}
