import os
import sys

def create_cpp_file(number):
    """
    根据输入的数字创建指定名称的cpp文件，并写入初始代码
    :param number: 输入的数字（整数）
    """
    # 拼接文件名：t + 数字 + .cpp
    filename = f"t{number}.cpp"
    
    # 检查文件是否已存在，避免覆盖
    if os.path.exists(filename):
        print(f"错误：文件 {filename} 已存在，不会覆盖！")
        return False
    
    # 要写入文件开头的代码
    init_code = """#include <bits/stdc++.h>
using namespace std;
"""
    
    try:
        # 以写入模式创建并打开文件，编码指定为utf-8保证兼容性
        with open(filename, 'w', encoding='utf-8') as f:
            f.write(init_code)
        print(f"成功创建文件：{filename}")
        return True
    except Exception as e:
        print(f"创建文件失败：{e}")
        return False

if __name__ == "__main__":
    # 处理命令行参数输入
    if len(sys.argv) != 2:
        print("使用方法：")
        print("  方式1（命令行参数）：python create_cpp.py 100")
        print("  方式2（交互式输入）：直接运行 python create_cpp.py 后按提示输入数字")
        # 交互式输入逻辑
        try:
            number_input = input("请输入要创建的文件数字编号：").strip()
            # 验证输入是否为数字
            number = int(number_input)
            create_cpp_file(number)
        except ValueError:
            print("输入错误！请输入有效的整数数字。")
        except KeyboardInterrupt:
            print("\n操作已取消。")
        except Exception as e:
            print(f"程序异常：{e}")
    else:
        # 从命令行参数获取数字
        try:
            number = int(sys.argv[1])
            create_cpp_file(number)
        except ValueError:
            print("输入错误！命令行参数必须是整数数字。")