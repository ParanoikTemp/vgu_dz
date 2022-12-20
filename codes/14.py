with open('nums.txt', encoding='utf-8') as f:
    text = f.read().replace('\n', ' \n').split(' ')
is_num = lambda x: not x.startswith('.') and not x.endswith('.') and x.replace('.', '', 1).isdigit()
nums = list(map(lambda x: str(float(x) * 2) if is_num(x) else x, text))
with open('nums.txt', 'w', encoding='utf-8') as f:
    f.write(' '.join(nums))
