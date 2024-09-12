# This script is used to update the progress of a task in the database.

import matplotlib.pyplot as plt
import matplotlib.font_manager as fm
import os

# 设置字体
font_path = '/usr/share/fonts/opentype/noto/NotoSansCJK-Regular.ttc'
font_prop = fm.FontProperties(fname=font_path)

# 数据
directory = 'submissions/'
all_items = os.listdir(directory)
members = [item for item in all_items if os.path.isdir(os.path.join(directory, item)) and item != 'README.md']
task_counts = {}
for member in members:
    folder_path = os.path.join(directory, member)
    items = os.listdir(folder_path)
    task_counts[member] = len(items)

for member, count in task_counts.items():
    print(f"{member}: {count}")


# 设置图形大小
plt.figure(figsize=(10, 6))

plt.barh(members, task_counts.values(), color='gold', label=f'已提交人数{len(members)}' )

# 显示图例
plt.legend(loc="upper right", prop = font_prop)

# 设置标题和标签
plt.title('任务轴', fontproperties = font_prop)
plt.xlabel('任务数量', fontproperties = font_prop)

x_ticks = range(0, 9, 1)
x_labels = [f'task{i-1}' for i in x_ticks]
plt.xticks(x_ticks, x_labels, fontproperties = font_prop)

for label in plt.gca().get_xticklabels() + plt.gca().get_yticklabels():
    label.set_fontproperties(font_prop)

# 存储图表
plt.savefig('assets/task_progress.png')
