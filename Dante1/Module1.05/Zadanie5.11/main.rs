fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).expect("Error");

    for i in input.chars() {
        if !i.is_digit(10) && i != '|' && i != '-' {
            panic!("Incorrect input");
        }
    }

    let mut result: [i64; 100] = [0; 100];
    let mut result_index: usize = 0;
    let mut sum: i64 = 0;

    let mut inside_segment: i32 = 0;
    let mut current_number: i64 = 0;
    let mut number_exists: i32 = 0;

    for i in 0..input.trim().len()
    {
        let mut current = input[i];

        if current == '|' || current == '\0'
        {
            if inside_segment == 1
            {
                sum += current_number;
                result[result_index] = sum;
                result_index += 1;
                sum = 0;
                current_number = 0;
            }
            else
            {
                result[result_index] = 0;
                result_index += 1;
            }
            inside_segment = 1;
            number_exists = 0;
        }
        else if current.isdigit(10)
        {
            current_number = current_number * 10 + (current - '0');
            number_exists = 1;
        }
        else if current == '-'
        {
            if number_exists == 1
            {
                sum = sum + current_number;
                current_number = 0;
                number_exists = 0;
            }
        }
    }


    for i in 0..result_index {
        print!("{} ", result[i]);
    }
}
