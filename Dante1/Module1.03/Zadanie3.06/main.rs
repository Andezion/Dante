fn main() {
    let mut result: i128 = 1;

    for _i in 0..20 {
        println!("{}", result);
        result = result * 10;
    }
}
