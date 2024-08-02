# Problem

WSL's virtual hard drive file (vhdx) doesn't shrink automatically after you delete data, wasting disk space.

# Solution

1. **Shutdown WSL**:

    ```
    wsl --shutdown
    ```

2. **Open DiskPart**:

    ```
    diskpart
    ```

3. **Shrink and Compact the Virtual Disk**:

    a. Select the virtual disk file (replace with your path):

    ```
    select vdisk file="C:\WSL-Distros\…\ext4.vhdx"
    ```

    b. Attach the virtual disk read-only:

    ```
    attach vdisk readonly
    ```

    c. Compact the virtual disk:

    ```
    compact vdisk
    ```

    d. Detach the virtual disk:

    ```
    detach vdisk
    ```

    e. Exit DiskPart:

    ```
    exit
    ```
