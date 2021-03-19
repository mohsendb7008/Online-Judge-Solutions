# Spavanac
H, M = map(int, input().split())
print(f'{H} {M - 45}' if M >= 45 else f'{(H - 1) % 24} {M + 15}')
