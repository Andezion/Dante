fn main() {
    let mut array: [i32; 100] = [0; 100];
    let mut size: usize = 0;

    let mut sum: i32 = 0;
    let mut min: i32 = i32::MAX;
    let mut max: i32 = i32::MIN;

    let mut input: String = String::new();
    println!("Enter: ");

    for i in 0..100 {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Incorrect");
        array[i] = input.trim().parse().expect("Incorrect");

        if array[i] == -1 {
            break;
        }

        sum += array[i];
        if max < array[i] {
            max = array[i];
        }
        if min > array[i] {
            min = array[i];
        }
        size += 1;
    }

    println!("\n{size} {min} {max} {} {sum}", sum as f32/ size as f32);

    for i in 0..size {
        if array[i] == min {
            print!("{} ", i);
        }
    }

    println!();

    for i in 0..size {
        if array[i] == max {
            print!("{} ", i);
        }
    }
}
