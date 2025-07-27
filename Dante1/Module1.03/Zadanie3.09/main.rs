fn main() {
    for i in -10..11 {
        for j in -10..11 {
            if (i - j) * (i + j) == i * i + j * j {
                println!("{} {}", i, j);
            }
        }
    }
}
