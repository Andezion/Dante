fn main() {
    let mut input: String = String::new();

    let mut array: [i32; 100] = [0; 100];
    let mut size: usize = 0;

    let mut max: i32 = i32::MIN;
    let mut min: i32 = i32::MAX;

    println!("Enter: ");
    for _i in 0..100 {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Error");
        let temp: i32 = input.trim().parse().expect("Error");
        if temp == 0 {
            break;
        }
        array[size] = temp;
        size += 1;

        if array[size] > max {
            max = array[size];
        }
        if array[size] < min {
            min = array[size];
        }
    }
    if size < 2 {
        panic!("error");
    }

    let mut suma: i32 = 0;
    let mut counter: i32 = 0;
    for i in 0..size {
        if array[i] == max || array[i] == min {
            suma += i as i32 ;
            counter += 1;
        }
    }

    if counter == 0 {
        panic!("error");
    }

    println!("{}", array[suma as usize / counter as usize])
}
