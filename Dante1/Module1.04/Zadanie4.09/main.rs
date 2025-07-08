use std::cmp::{max, min};

fn main() {
    let mut array:[i32; 100] = [0; 100];
    let mut maximum: i32 = i32::MIN;
    let mut minimum: i32 = i32::MAX;
    
    let mut size: i32 = 0;
    let mut sum: i32 = 0;
    
    let mut input: String = String::new();
    println!("Enter: ");
    
    for i in 0..100 {
        input.clear();
        
        std::io::stdin().read_line(&mut input).expect("Incorrect read");
        array[i] = input.trim().parse().expect("Incorrect parse");
        
        if array[i] == -1 {
            break;
        }
        
        sum += array[i];
        maximum = max(maximum, array[i]);
        minimum = min(minimum, array[i]);
        
        size += 1;
    }
    
    println!("{} {} {} {} {}", size, minimum, maximum, sum as f32 / size as f32, sum);
}
