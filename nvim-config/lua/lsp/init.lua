require('lspconfig').lua_ls.setup {
  cmd = { 'lua-language-server' },
  filetypes = { 'lua' },
  settings = {
    Lua = {
      runtime = {
        version = 'LuaJIT',
      }
    }
  }
}


require('lspconfig').clangd.setup {
  cmd = { 'clangd' },
  filetypes = { 'c', 'cpp', 'cc', 'h', 'hh', 'hpp' },
}
