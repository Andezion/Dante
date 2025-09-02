fn main() {
    let mut input: String = String::new();
    let mut size: usize = 0;

    let mut array: [i32; 100] = [0; 100];

    println!("Enter: ");
    for _i in 0..100 {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("err");
        array[size] = input.trim().parse().expect("err");
        if array[size] == 0 {
            break;
        }
        size += 1;
    }

    if size < 1 {
        println!("Not enough data available");
    }

    let mut sum: i32 = 0;
    for i in 0..size {
        sum = sum + array[i];
    }
    let temp1: f32 = sum as f32 / size as f32;

    let mut new_sum: f32 = 0.0;
    for i in 0..size {
        new_sum = new_sum + f32::powi(array[i] as f32 - temp1, 2);
    }

    let new_default: f32 = f32::sqrt(new_sum / size as f32);

    let mut temporary: u8 = 0;
    for i in 0..size {
        if f32::abs(temp1 - array[i] as f32) > new_default {
            print!("{} ", array[i]);
            temporary = 1;
        }
    }
    if temporary == 0 {
        print!("Nothing to show");
    }
}
