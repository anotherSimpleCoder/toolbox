--[[require('lspconfig').lua_ls.setup {
  cmd = { 'lua-language-server' },
  filetypes = { 'lua' },
  settings = {
    Lua = {
      runtime = {
        version = 'LuaJIT',
      }
    }
  }
}]]

require('lspconfig').bashls.setup {
  cmd = { 'bash-language-server', 'start' },
  filetypes = { 'sh' }
}

require('lspconfig').clangd.setup {
  cmd = { 'clangd' },
  filetypes = { 'c', 'cpp', 'cc', 'h', 'hh', 'hpp' },
}
